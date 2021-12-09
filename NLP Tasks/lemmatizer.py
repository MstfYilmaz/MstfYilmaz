import nltk
from nltk.stem import WordNetLemmatizer
wordnet_lemmatizer = WordNetLemmatizer()

sentence = "Leicester City FC, has rented Cengiz Ünder including transferring option."

sentence_words = nltk.word_tokenize(sentence)

for word in sentence_words:
    print ("{0:20}{1:20}".format(word,wordnet_lemmatizer.lemmatize(word, pos='v')))

import spacy
sp = spacy.load('en_core_web_sm')
sentence = sp(u'Leicester City FC, has rented Cengiz Ünder including transferring option.')
for word in sentence:
    print(word.text, word.lemma_)

