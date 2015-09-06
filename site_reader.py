#############################
# FIFTH SENSE (PennApps '15)#
#@author: rajat mehndiratta #
#@version: 0.1              #
#@license: GPL              #
#############################

import requests
from HTMLParser import HTMLParser

class MLStripper(HTMLParser):

    def __init__(self):
        self.reset()
        self.fed = []

    def handle_data(self, d):
        self.fed.append(d)

    def get_data(self):
        return ''.join(self.fed)

class SiteReader(object):

    def __init__(self, url):
        self.url = url

    def getPageData(self):
        r = requests.get(self.url)
        return r.text

    def parseSite(self):
        siteData = self.getPageData()
        stripper = MLStripper()
        stripper.feed(siteData)
        return stripper.get_data()