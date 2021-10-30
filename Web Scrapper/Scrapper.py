from selenium import webdriver
from bs4 import BeautifulSoup
import pandas as pd
import time


def scrap(url, file, load_time):
    # Specify the path of chromedriver.exe
    driver = webdriver.Chrome()
    driver.get(url)
    time.sleep(load_time)
    soup = BeautifulSoup(driver.page_source, 'html5lib')

    # print(soup.prettify())
    driver.close()
    entries = 20  # Number of Job entries you want to fetch
    pages = 5  # Number of pages you want to fetch
    results = soup.find(class_='list')
    jobs = results.find_all('article', class_='jobTuple bgWhite br4 mb-8')
    count = 0
    skillslist = []
    skillcount = {}
    df = pd.DataFrame(columns=['Company', 'Description', 'Experience', 'Locality', 'Salary', 'Skills'])

    for i in range(0, pages):
        time.sleep(0.5)
        if count > entries - 1:  # Limit number of entries to integer entries
            break
        for job in jobs:
            if count > entries - 1:  # Limit number of entries to integer entries
                break

            # Company Name
            company = job.find('a', class_='subTitle ellipsis fleft')

            # Job Description
            des = job.find("div", class_="job-description fs12 grey-text")
            if des is None:
                continue
            else:
                description = des.text

            # Experience in Years
            exp_l = job.find('li', class_='fleft grey-text br2 placeHolderLi experience')
            exp = exp_l.find('span', class_='ellipsis fleft fs12 lh16')
            if exp is None:
                continue
            else:
                experience = exp.text

            # Locality
            loc_l = job.find('li', class_='fleft grey-text br2 placeHolderLi location')
            loc = loc_l.find('span', class_='ellipsis fleft fs12 lh16')
            if loc is None:
                continue
            else:
                location = loc.text

            # Salary
            sal_l = job.find('li', class_='fleft grey-text br2 placeHolderLi salary')
            sal = sal_l.find('span', class_='ellipsis fleft fs12 lh16')
            if sal is None:
                continue
            else:
                salary = sal.text

            # Skills
            skills = []
            skillSet = job.find('ul', class_='tags has-description')
            for skill in skillSet.find_all('li', class_='fleft fs12 grey-text lh16 dot'):
                key = skill.text
                skills.append(key)

                # Skill frequency list
                if skillcount.get(key) is not None:
                    skillcount[key] = skillcount[key] + 1
                else:
                    skillcount[key] = 1
                skillslist.append(skills)

            #  Insert values in dataframe
            df = df.append(
                {'Company': company.text, 'Description': description,
                 'Experience': experience, 'Locality': location, 'Salary': salary, 'Skills': skills}, ignore_index=True)
            count += 1

    print(df.shape)
    # print(df.head(20))
    if df.empty:
        print("Data cannot be fetch Try again.")
        scrap(url, file, 5)
    else:
        df.to_excel(file, index=False)

    sorted_dict = dict(sorted(skillcount.items(), key=lambda item: item[1], reverse=True))
    df2 = pd.DataFrame('Skill', 'Frequency')
    df2.append('skill': skillname, 'Frequency': frequncy)
    print(sorted_dict)

    # Use this line for xls file. Warning : xls is no longer supported by python except pandas.
    # df.to_excel("C:/Users/Anand/OneDrive/Desktop/Git/Web Scrapper/data.xls", index=False)
