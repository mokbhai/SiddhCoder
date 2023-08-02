ques = ["OKR stands for objectives and key results?", "LLCs are a combination of characteristics of a partnership and a corporation?", "SWOT Analysis is a personality test used to determine and screen job applications?",
        "No shares of the company can be sold during the IPO lockup period?", "The term inflation refers to a general rise in the prices of most products and services?"]

ans = [0, 0, 1, 1, 0, 1]
correct = incorrect = 0

for i in range(0, 5):
    print('Ques', i+1, ques[i], '/n')
    trfl = int(input("For true - 0  Or For false - 1: "))
    if trfl == ans[i]:
        print("Congratulate!! Your answer is Correct /nMarks +1")
        correct += 1
    else:
        print("OOPS!! Your answer is Incorrect /nMarks +0")
        incorrect += 1
print("Your Total Score = ", correct)
print("Total incorrect answer = ", incorrect)
