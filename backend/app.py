from flask import Flask, jsonify, request
import json

app = Flask(__name__)


# @app.route('/')
# def hello():
#     return 'Hello, World!'

@app.route('/', methods=["POST"])
def post_data():
    data = request.json
    return(jsonify(data))


    return "The data is being posted into database"

if __name__ == "__main__":
    app.run(host="localhost", port=8080, debug=True)