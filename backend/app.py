from flask import Flask, jsonify, request
import firebase_admin
from firebase_admin import credentials
from firebase_admin import firestore
from datetime import datetime
import numpy as np
from scipy.signal import argrelextrema

# Use the application default credentials
cred = credentials.ApplicationDefault()
firebase_admin.initialize_app(cred, {
    'projectId': "form-check-326415",
})

db = firestore.client()

app = Flask(__name__)

@app.route('/', methods=["GET"])
def hello():
    doc_ref = db.collection(u'users').document(u'alovelace')
    doc_ref.set({
        u'first': u'Ada',
        u'last': u'Lovelace',
        u'born': 1815
    })
    return "Hello"



@app.route('/', methods=["POST"])
def post_data():
    """
    data = {"data": [1,2,3,4,5,...50]}
    :return:
    """
    data = request.json

    date_time = datetime.now()
    current_date = date_time.strftime("%Y-%m-%d")
    current_time = date_time.strftime("%H:%M:%S")

    data1 = {current_time : {u'data': data["data"]}}
    doc_ref = db.collection(u'pushups_tirth').document(current_date)
    doc_ref.set(data1, merge=True)
    return jsonify(data)


@app.route('/<date>', methods=["GET"])
def get_data(date):
    doc_ref = db.collection(u'pushups').document(date)
    doc = doc_ref.get()

    values_list = []

    if doc.exists:
        data_doc = doc.to_dict()
        #return jsonify(data_doc)
        for key in data_doc:
            values_list.extend(data_doc[key]["data"])

        values_array = np.array(values_list)

        #gives array of indeces of local maxima, aka idedally top of the pushup, and second line for minima
        max_ind = argrelextrema(values_array, np.greater)
        min_ind = argrelextrema(values_array, np.less)

        #return {'thing': values_array.tolist()}

        good_pushups_top = []
        good_pushups_bot = []
        bad_pushups = []
        total_pushups = len(min_ind[0])

        for counter, index in enumerate(max_ind[0]):
            degree = values_array[index]
            percentage = (abs(degree)/90)*100
            if percentage >= 90:
                good_pushups_top.append([counter, percentage])
            else:
                bad_pushups.append([counter, percentage])

        for counter, index in enumerate(min_ind[0]):
            degree = values_array[index]
            percentage = (abs(degree)/90)*100
            if percentage <= 10:
                good_pushups_bot.append([counter, 100-percentage])
            else:
                bad_pushups.append([counter, 100-percentage])

        good_counter = 0
        final_good_pushups = []

        for i in good_pushups_top:
            for j in good_pushups_bot:
                if i[0] == j[0]:
                    good_counter += good_counter
                    average_percentage = (i[1]+j[1])/2
                    final_good_pushups.append([i[0], average_percentage])

        bad_counter = total_pushups - good_counter

        # print(total_pushups)
        # print(good_counter)
        # print(final_good_pushups)
        # print(bad_counter)
        # print(bad_pushups)

        #return {'thing': final_good_pushups}

        return jsonify({"totalPushups":total_pushups, "numberOfGoodPushups":good_counter,
                        "goodPushupsData":final_good_pushups, "numberOfBadPushups":bad_counter,
                        "badPushupsData":bad_pushups})

    else:
        return jsonify({"error":"document not found"})

if __name__ == "__main__":
    app.run(host="localhost", port=8080, debug=True)