import Scrapper
import Format

print("Enter job designation to search jobs for : ")
designation = input()

url = "https://www.naukri.com/" + Format.format_designation(designation, False) + "-jobs"
file = "C:/Users/Anand/OneDrive/Desktop/Git/Web Scrapper/data.xlsx"

print(url)
Scrapper.scrap(url, file, 3)  # Third parameter is load time ie. how long to wait before parsing HTML after opening link

# If theres no output even after retry try increasing third parameter in above function call from 3 to 7 or more,
# Higher load_time is recommended for slower internet Load time for page recommended bigger value if internet is slow
# Also increase same parameter in Scrapper.py line 91 if needed.
