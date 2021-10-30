import Scrapper
import Format

print("Enter job designation to search jobs for : ")
designation = input()

url = "https://www.naukri.com/" + Format.format_designation(designation, False) + "-jobs"
file = "C:/Users/Anand/OneDrive/Desktop/Git/Web Scrapper/"   # Must give path of project root directory

print(url)
Scrapper.scrap(url, file, 3)  # Third parameter is load time ie. how long to wait before parsing HTML after opening link

# If theres no output even after retry try increasing third parameter in above function call from 3 to 7 or more,
# Higher load_time is recommended for slower internet Load time for page recommended bigger value if internet is slow
# Also increase same parameter in Scrapper.py line 91 if needed.

# Chromedriver installation is recommended for the script to run
# Use pip install chromedriver
# Also make sure then chrome driver is added to the path environment variable
# For help about Chromedriver setup refer this https://cppsecrets.com/users/11429798104105115104101107117115104119971049754494864103109971051084699111109/Python-chromedriver-executable-needs-to-be-in-PATH.php