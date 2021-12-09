import RAKE
import operator

stop_dir = "C:\\Users\\Mustafa\\Desktop\\stopword.txt"
rake_object = RAKE.Rake(stop_dir)
with open ("C:\\Users\\Mustafa\\Desktop\\text1.txt", "r", encoding = "utf-8") as file:
     subtitles = file.read()

def sort_tuple(tup):
    tup.sort(key = lambda x: x[1])
    return tup


keywords = sort_tuple(rake_object.run(subtitles)) [-10:]
print ("keywords: ", keywords)