import csv

with open("csv_file.csv","r") as file:
    reader = csv.DictReader(file)
    count = {}
    for row in reader:
        fav = row["languages"];
        if fav in count:
            count[fav] += 1
        else:
            count[fav] = 1

for favorite in sorted(count, reverse = True):  # change order of print out
    print(f"{favorite}: {count[favorite]}")

# sorted by value
def get_value(language):
    return count[language]

for favorite in sorted(count, key = get_value, reverse = True):  # change order of print out
    print(f"{favorite}: {count[favorite]}")


favorite = input("Favorite: ")
if favorite in count:
    print(f"{favorite}: {count[favorite]}")