from flask import Flask
from site_reader import *
import json

app = Flask(__name__)

@app.route("/getText")
def getText():
    url = request.args.get('url')
    return getSiteText(url)

if name == "__main__":
    app.run()