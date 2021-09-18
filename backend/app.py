from flask import Flask, jsonify, request
import json

app = Flask(__name__)

all_data = {}

@app.route('/', methods=["GET"])
def hello():
    return jsonify(all_data)

@app.route('/', methods=["POST"])
def post_data():
    data = request.json
    if data['id'] in all_data:
        return jsonify({"error": "id already exists"})
    
    all_data[data['id']] = data
    return(jsonify(data))

if __name__ == "__main__":
    app.run(host="localhost", port=8080, debug=True)