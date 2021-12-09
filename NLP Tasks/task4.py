from nltk import word_tokenize
from textblob import TextBlob 
with open("C:\\Users\\Mustafa\\Desktop\\Turkish-Aksu\\Turkish-Aksu\\03\\03b.cha", "r", encoding='utf-8') as file:
     text1 = file.read()
        
blob_object = TextBlob(text1)
 
text1 = re.sub('<.*>','',text1)
text1 = re.sub('ENDOFARTICLE.','',text1)  
punctuationNoPeriod = "[" + re.sub("\.","",string.punctuation) + "]"
text1 = re.sub(punctuationNoPeriod, "", text1)

print ("pos tags:\n")
print (blob_object.tags)
print ("\n")

print("Pos Counters:\n")
tokens = nltk.word_tokenize(text1)
nltk.pos_tag(tokens)