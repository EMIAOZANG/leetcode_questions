import os

def countSpaces(l):
    i = 0
    while l[i] == " " and i < len(l):
       i += 1
    return i

def solution(s):
    lines = s.split('\n')
    imgPaths = set([])
    currPath = [""]
    for line in lines:
        lv = countSpaces(line)
        
        ext = os.path.splitext(line)[-1]
        while len(currPath)-1 > lv and len(currPath) > 0:
            currPath.pop()
        if ext == "": #dir
            currPath.append(line.strip()) #append current path
        elif ext == '.jpeg' or ext == '.png' or ext == '.gif':
            imgPaths.add("/".join(currPath))

    sumLength = 0
    print imgPaths
    for item in imgPaths:
        sumLength += len(item)

    return sumLength

S = "dir1\n dir11\n dir12\n  picture.jpeg\n  dir121\n  file1.txt\ndir2\n file2.gif"
print solution(S)



            




        
        
        


