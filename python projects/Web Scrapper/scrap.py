#Importing requred modules

import requests
from bs4 import BeautifulSoup
from requests.models import to_native_string

#Converts the multiword designation string into k value for naukri.com designation key value with required number of postings .

def format_designation(designation,value):
    #for dash '-' separated designation use value False
    #for value '%20' separated return use value True

    words = designation.split()
    text=""
    text+=words[0]
    if(len(words)>1):
        for i in range(len(words)-1):
            if value:
                text+="%20"
            else:
                text+="-"
            text+=words[i+1]
    return text



def scrap(designation):

    #value separated designation text has %20 between every word in designation
    #https://www.naukri.com/web-developer-jobs?k=web%20developer add only if needed

    dash_separated=format_designation(designation,False)  #comments - example= "this-is-an-example"
    # value_separated=format_designation(designation,True)  #comments - example= "this%20is%20an%20example"        #comments - only add if needed k value


    #Creates proper URL with sub-pages and designation key value pairs supported by 'naukri.com'
    url = f"https://www.naukri.com/{dash_separated}-jobs" #+"?k={value_separated}"                      #comments -  only add if needed k value
    r= requests.get(url)
    html = r.content
    return url

#Parsing HTMl
    soup =BeautifulSoup(html,'html.parser')
    print(soup)
designation = "python web developer"
print(scrap(designation))