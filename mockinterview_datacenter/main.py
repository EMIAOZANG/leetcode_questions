"""
using two-level hash structure
"""
class MasterNode:
    def __init__(self):
        self._plist = {}

    def add_datacenter(self,dc):
        for item in dc:
            if item not in self._plist:
                self._plist[item] = {}
