'''
CAUTION: in python evaluations, -3/2 == -2!
postfix expression evaluation:

'''
import re

class Solution(object):
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        p = re.compile(r'\d+|\+|\-|\*|\/') 
        l = p.findall(s.strip())

        #two stacks, one for numbers and one for operators
        num_stack = []
        op_stack = []

        neg_flag = False
        
        for item in l:
            try:
                ch = int(item)
                if neg_flag:
                    ch = 0-ch
                    neg_flag = False
                num_stack.append(ch)

                if len(op_stack) != 0:
                    #if op stack top is * or / compute the result
                    if op_stack[-1] == '*':
	                if len(num_stack) >= 2:
	                    num1 = num_stack.pop()
	                    num2 = num_stack.pop()
                        num_stack.append(num1*num2)
                        op_stack.pop()
                    elif op_stack[-1] == '/':
	                if len(num_stack) >= 2:
	                    num1 = num_stack.pop()
	                    num2 = num_stack.pop()
                        if num2 < 0:
                            num_stack.append(-(-num2/num1)) #Get ceiling when num2 is a negative number
                        else:
                            num_stack.append(num2/num1)
                        op_stack.pop()
            except:
                if item == '-':
                    item = '+'
                    neg_flag = True
                op_stack.append(item) #append operator to the stack
            
        

        while len(op_stack) > 0:
            op = op_stack.pop()
            num1 = num_stack.pop()
            num2 = num_stack.pop()
            
            if op == '+':
                num_stack.append(num1+num2)
            elif op == '-':
                num_stack.append(num1-num2)

        return num_stack.pop()     


#test block
s = ['2*3+5*3/2','1-1+1']
sls = Solution()
print map(sls.calculate,s)






