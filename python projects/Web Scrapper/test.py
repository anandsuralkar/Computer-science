from bs4 import BeautifulSoup
import time
import requests
import pandas as pd

df = pd.DataFrame(columns=['Title','Company','Ratings','Reviews','Experience','Salary','Location','Job_Post_History','URL'])

for param in range(1):
    url = "https://www.naukri.com/pytho-developer-jobs?k=pytho%20developer"
    
    # Specify the path of chromedriver.exe     
    #driver = webdriver.Chrome("F:\\Selenium\\chromedriver.exe")
    r= requests.get(url)
    html = r.content
    print(r)
    soup = BeautifulSoup(html)
    session=requests.sessions
    print (r.content)
    time.sleep(2)
    """
    # print(soup.prettify())
    for i in range(100):
        results=soup.session.get('div')
    #job_elems = soup.find('article',class_='jobTuple bgWhite br4 mb-8')
        print(results)
    """
    """
    

    for job_elem in job_elems:

        # URL to apply for the job     
        URL = job_elem.find('a',class_='title fw500 ellipsis').get('href')
    #     print(URL.strip())

        # Post Title
        Title = job_elem.find('a',class_='title fw500 ellipsis')

        # Company Name
        Company = job_elem.find('a',class_='subTitle ellipsis fleft')

        # Ratings
        rating_span = job_elem.find('span',class_='starRating fleft dot')
        if rating_span is None:
            continue
        else:
            Ratings = rating_span.text

        # Reviews Counts
        Review_span = job_elem.find('a',class_='reviewsCount ml-5 fleft blue-text')
        if Review_span is None:
            continue
        else:
            Reviews = Review_span.text

        # Years of experience Required
        Exp = job_elem.find('li',class_='fleft grey-text br2 placeHolderLi experience')
        Exp_span = Exp.find('span',class_='ellipsis fleft fs12 lh16')
        if Exp_span is None:
            continue
        else:
            Experience = Exp_span.text

        # Salary offered for the job
        Sal = job_elem.find('li',class_='fleft grey-text br2 placeHolderLi salary')
        Sal_span = Sal.find('span',class_='ellipsis fleft fs12 lh16')
        if Sal_span is None:
            continue
        else:
            Salary = Sal_span.text

        # Location for the job post
        Loc = job_elem.find('li',class_='fleft grey-text br2 placeHolderLi location')
        Loc_exp = Loc.find('span',class_='ellipsis fleft fs12 lh16')
        if Loc_exp is None:
            continue
        else:
            Location = Loc_exp.text

        # Number of days since job posted
        Hist = job_elem.find("div",["type br2 fleft grey","type br2 fleft green"])
        Post_Hist = Hist.find('span',class_='fleft fw500')
        if Post_Hist is None:
            continue
        else:
            Post_History = Post_Hist.text

    #   Appending data to the DataFrame 
        df=df.append({'URL':URL,'Title':Title.text,'Company':Company.text,'Ratings':Ratings,'Reviews':Reviews,'Experience':Experience,'Salary':Salary,'Location':Location,'Job_Post_History':Post_History},ignore_index = True)
        """