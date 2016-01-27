"""
Just Consider More Boundary Conditions
0: Zero
1 - 20: Dict
"""
class Solution(object):
    def convertSection(self,sec):
        sec_str = ""
        word_dict = {1:"One",2:"Two",3:"Three",4:"Four", 5:"Five",6:"Six", 7:"Seven", 8:"Eight", 9:"Nine", 10:"Ten", 11:"Eleven", 12:"Twelve", 13:"Thirteen", 14:"Fourteen", 15:"Fifteen", 16:"Sixteen", 17:"Seventeen", 18:"Eighteen", 19:"Nineteen", 20:"Twenty", 30:"Thirty", 40:"Forty", 50:"Fifty", 60:"Sixty", 70:"Seventy", 80:"Eighty", 90:"Ninety"}

        print sec / 100
        if sec / 100 in word_dict:
            sec_str += word_dict[sec/100] + " " + "Hundred"
        try:
            if sec % 100 <= 20:
                sec_str += " " + word_dict[sec%100]
            else:
                sec = sec % 100
                sec_str += " " + word_dict[(sec/10)*10] 
                sec = sec % 10
                if sec in word_dict:
                    sec_str += " "
                    sec_str += word_dict[sec]
        except:
            pass

        return sec_str
    def numberToWords(self, num):
        """
        :type num: int
        :rtype: str
        """

        lv = 0
        lv_dict = {0:"", 1:"Thousand", 2:"Million", 3:"Billion", 4:"Trillion"}
        if num == 0:
            return "Zero"
        section_str_list = []

        while num > 0:
            print num
            if num % 1000 > 0:
                section_str_list.append(lv_dict[lv])

            sec_str = self.convertSection(num % 1000)
            if sec_str != "":
                section_str_list.append(sec_str.strip())
            num /= 1000
            lv += 1

        section_str_list[:] = section_str_list[::-1] #reverse string
        return " ".join(section_str_list).strip()



sls = Solution()
print sls.numberToWords(100010)

