# -*- coding:utf-8 -*-
import nltk, re, string, collections
from nltk.util import ngrams # function for making ngrams


with open("C:\\Users\\Mustafa\\Desktop\\corpus.txt", "r", encoding='utf-8') as file:
    text = file.read()

text = re.sub('<.*>','',text)

text = re.sub('ENDOFARTICLE.','',text)

punctuationNoPeriod = "[" + re.sub("\.","",string.punctuation) + "]"
text = re.sub(punctuationNoPeriod, "", text)

text[0:10000]
tokenized = text.split()

Bigrams = ngrams(tokenized, 2)
Trigrams = ngrams(tokenized,3)

BigramFreq = collections.Counter(Bigrams)
TrigramFreq = collections.Counter(Trigrams)
print ("Bigrams are:\n")
print (BigramFreq.most_common(5))
print ("Trigrams are:")
TrigramFreq.most_common(5)