from flask import Flask, jsonify, request
import firebase_admin
from firebase_admin import credentials
from firebase_admin import firestore

# Use the application default credentials
cred = credentials.ApplicationDefault()
firebase_admin.initialize_app(cred, {
    'projectId': "form-check-326415",
})

db = firestore.client()

app = Flask(__name__)

@app.route('/', methods=["GET"])
def hello():
    return "Hello"

@app.route('/', methods=["POST"])
def post_data():
    data = request.json
    return jsonify(data)

if __name__ == "__main__":
    app.run(host="localhost", port=8080, debug=True)