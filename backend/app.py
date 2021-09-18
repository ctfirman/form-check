from flask import Flask, jsonify, request
from flask_sqlalchemy import SQLAlchemy
from datetime import datetime

app = Flask(__name__)
# app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///test.db'
# db = SQLAlchemy(app)

# class Workout(db.Model):
#     id = db.Column(db.Integer, primary_key=True)
#     content = db.Column(db.Float, nullable=False)
#     date_added = db.Column(db.DateTime, default=datetime.utcnow)

#     def __repr__(self):
#         return f"<Created {self.id}>"

# displayed = {}

@app.route('/', methods=["GET"])
def hello():
    # all_data = Workout.query.order_by(Workout.date_added).all()
    # for i, data in enumerate(all_data):
    #     # displayed[i]["id"] = data.id
    #     displayed[i]["content"] = data.content
    #     displayed[i]["id"] = data.date_added
    
    # return jsonify(displayed)
    return "Hello"

@app.route('/', methods=["POST"])
def post_data():
    data = request.json
    # new_data_entry = Workout(content=data["readings"])

    # try:
    #     db.session.add(new_data_entry)
    #     db.session.commit()
    #     return jsonify(data)
    # except:
    #     return(jsonify({"error": "Couldn't add data"}))
    return jsonify(data)

if __name__ == "__main__":
    app.run(host="localhost", port=8080, debug=True)