import requests
import json

url = "https://form-check-hixwog3m7q-uc.a.run.app/"

data = {"data": 10.1}

response = requests.post(url, json=data)

print(json.dumps(response.json(), indent=2))