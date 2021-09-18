from flask import Flask

app = Flask(__name__)


@app.route('/')
def hello():
    return 'Hello, World!'

@app.route('/pushData')
def get_data():
    return "The data is being posted into database"

if __name__ == "__main__":
    app.run(host="localhost", port=8080, debug=True)