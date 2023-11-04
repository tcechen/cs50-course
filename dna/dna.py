import csv
import sys


def main():
    # TODO: Check for command-line usage
    if len(sys.argv) < 3:
        print(f"Usage: python dna.py data.csv sequence.txt")
        sys.exit()

    # TODO: Read database file into a variable
    csv_db = []
    with open(sys.argv[1]) as file:
        reader = csv.reader(file)
        for row in reader:
            csv_db.append(row)

    # TODO: Read DNA sequence file into a variable
    dna_file = []
    with open(sys.argv[2]) as file:
        dna_file = file.read()

    # TODO: Find longest match of each STR in DNA sequence
    STR = []
    for i in range(1, len(csv_db[0])):
        count = longest_match(dna_file, csv_db[0][i])
        STR.append(count)

    # TODO: Check database for matching profiles
    for i in range(1, len(csv_db)):
        temp = csv_db[i][1 : len(csv_db)]
        temp = list(map(int, temp))
        if temp == STR:
            print(f"{csv_db[i][0]}")
            return 0

    print("No match")
    return 0


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):
        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:
            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
