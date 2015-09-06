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
    try:
        results['title'] = r['objects'][0]['title']
    except:
        results['title'] = r.get('title', "Untitled")
    try:
        results['text'] = r['objects'][0]['text']
    except:
        results['text'] = r.get('text', "No text found.")
    if results['title'] == "": results['title'] = "Untitled"
    if results['text'] == "": results['text'] = "No text found."
    results['length'] = len(results['text'])
    return json.dumps(results)
