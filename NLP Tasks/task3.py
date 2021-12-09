from collections import Counter
import nltk, re, string, collections
from nltk.util import ngrams # function for making ngrams
from nltk import word_tokenize

with open("C:\\Users\\Mustafa\\Desktop\\Turkish-Aksu\\Turkish-Aksu\\03\\03b.cha", "r", encoding='utf-8') as file:
    text1 = file.read()
with open("C:\\Users\\Mustafa\\Desktop\\haber.txt", "r", encoding='utf-8') as file:
    text2 = file.read()
    
# delete puncs------------------------------------------------------------
text1 = re.sub('<.*>','',text1)
text1 = re.sub('ENDOFARTICLE.','',text1)
text2 = re.sub('<.*>','',text2)
text2 = re.sub('ENDOFARTICLE.','',text2)

punctuationNoPeriod = "[" + re.sub("\.","",string.punctuation) + "]"
text1 = re.sub(punctuationNoPeriod, "", text1)
text2 = re.sub(punctuationNoPeriod, "", text2)

#---------------------------------------------------------------
#counter-------------------------------------
lower_case1 = text1.lower()
lower_case2 = text2.lower()
tokens1 = nltk.word_tokenize(lower_case1)
tokens2 = nltk.word_tokenize(lower_case2)
tags1 = nltk.pos_tag(tokens1)
tags2 = nltk.pos_tag(tokens2)
counts1 = Counter(tag for word, tag in tags1)
counts2 = Counter(tag for word, tag in tags2)
print("Pos Counters:\n")
print(counts1)
print(counts2)
#-----------------------------------------------

tokenized1 = text1.split()
tokenized2 = text2.split()

Unigrams1 = ngrams(tokenized1, 1)
Bigrams1 = ngrams(tokenized1, 2)
Trigrams1 = ngrams(tokenized1,3)
Unigrams2 = ngrams(tokenized2, 1)
Bigrams2 = ngrams(tokenized2, 2)
Trigrams2 = ngrams(tokenized2,3)

UnigramFreq1 =collections.Counter(Unigrams1)
BigramFreq1 = collections.Counter(Bigrams1)
TrigramFreq1 = collections.Counter(Trigrams1)
UnigramFreq2 =collections.Counter(Unigrams2)
BigramFreq2 = collections.Counter(Bigrams2)
TrigramFreq2 = collections.Counter(Trigrams2)

print("Unigrams in text1 are:\n")
print (UnigramFreq1.most_common(5))
print ("Bigrams in text1 are:\n")
print (BigramFreq1.most_common(5))
print ("Trigrams in text1 are:\n")
print (TrigramFreq1.most_common(5))
print("Unigrams in text2 are:\n")
print (UnigramFreq2.most_common(5))
print ("Bigrams in text2 are:\n")
print (BigramFreq2.most_common(5))
print ("Trigrams in text2 are:\n")
print (TrigramFreq2.most_common(5))