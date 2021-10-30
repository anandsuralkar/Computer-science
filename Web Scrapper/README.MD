Its recommended to use pycharm IDE for smooth environment setup
Also chrome browser must be installed as chromedriver is used in the script

install following modules:-

pandas
time
selenium
bs4
chromedriver

Use pip install to install chromedriver in Your PC Global directory
After Cromedriver installation add local path to chromedriver root folder in path environment variable
refer link provided at the end if needed

To start the script run "main.py"
Enter the job designation you want to fetch Key-Skills for and press enter
The fetched Key-Skills data will be stored in data.xlsx

Furthermore, frequency of each Key-Skill is stored in Frequency.xlsx in the descending order ie. most frequent Key-Skill at the top and least one at the bottom.



If issues occur regarding webdriver refer this.
Some versions of webdriver are not compatible with most pandas version and also
https://cppsecrets.com/users/11429798104105115104101107117115104119971049754494864103109971051084699111109/Python-chromedriver-executable-needs-to-be-in-PATH.php