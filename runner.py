import random
import itertools

def runner(List):
    for i in range(len(List)):
        if i + 1 <= len(List):
            for j in range(i + 1, len(List)):
                if List[i] > List[j]:
                    List[j] = List[i]
    List = list(set(List))
    return len(List)                

def main(n):
    List = list(itertools.permutations(range(n), n))
    n = 0
    for i in range(len(List)):
        n = runner(list(List[i])) + n

    print(float(n) / len(List))

main(2)
