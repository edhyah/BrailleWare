from flask import Flask
from flask import request
from flask import Response
from site_reader import *
import json

app = Flask(__name__)

@app.route("/getText")
def getText():
    url = request.args.get('url')
    return getSiteText(url)

if __name__ == "__main__":
    app.run(host="45.79.149.238", debug=True)
