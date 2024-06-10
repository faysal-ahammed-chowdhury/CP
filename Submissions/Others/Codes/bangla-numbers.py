number = 23764


name = ['kuti', 'lakh', 'hajar', 'shata', ]

numbers = []

i = 0


while (number > 0):
    if i == 0:
        num1 = number % 10
        number /= 10
        num2 = number % 10
        number /= 10
        num = num2*10+num1
        numbers.append(num)
