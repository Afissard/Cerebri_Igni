"""
This is a test to see if I'm
realy sure of what am I doing
"""

def main():
    hello = "+[-->-[>>+>-----<<]<--<---]>-.>>>+.>>..+++[.>]<<<<.+++.------.<<-.>>>>+."
    program = "++++++++++++++++++++++++++++++++++++++++++++++++."
    data = [0] * 255
    data_ptr = 0

    for i in range(len(hello)):
        if program[i] == ">":
            data_ptr +=1
        elif program[i] == "<":
            data_ptr -= 1
        elif program[i] == "+":
            data[data_ptr] += 1
        elif program[i] == "-":
            data[data_ptr] -= 1
        elif program[i] == ".":
            print(data[data_ptr])
        elif program[i] == ",":
            data[data_ptr] = int(input("input between 0-255 :"))
        

if __name__ == "__main__":
    main()