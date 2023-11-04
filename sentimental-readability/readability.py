# TODO
from cs50 import get_string


def main():
    str = get_string("Text: ")
    index = calcalution(str)
    print_grade(index)


def calcalution(str):
    letters = 0
    words = 0
    sentences = 0

    for s in str:
        if s.isalpha():
            letters += 1
        elif s.isspace():
            words += 1
        elif s == "." or s == "?" or s == "!":
            sentences += 1

    words = words + 1
    index = cal_coleman_index(letters, words, sentences)
    return index


def cal_coleman_index(letters, words, sentences):
    # calculate Coleman-Liau index
    L = 100 * letters / words
    S = 100 * sentences / words
    index = int(round(0.0588 * L - 0.296 * S - 15.8))
    return index


def print_grade(index):
    if index < 1:
        print("Before Grade 1")
    elif index >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {index}")


main()
