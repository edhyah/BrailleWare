import requests
import json

APIToken = "2a6991cb5594e889e9bbb0330072624f"

def getSiteText(url):
    site = "http://api.diffbot.com/v3/article"
    params = dict()
    params['token'] = APIToken
    params['url'] = url
    r = requests.get(url=site, params=params)
    results = dict()
    r = r.json()
    results['title'] = r.get('title', "Untitled")
    results['text'] = r.get('text', "No text found.")
    results['length'] = len(results['text'])
    return json.dumps(results)