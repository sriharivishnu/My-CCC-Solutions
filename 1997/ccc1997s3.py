# games between u u & o o

t = int(input())


for a in range(t):
    undefeated = int(input())
    one = 0
    eliminated = 0
    round = 0

    print(
        f"Round {round}: {undefeated} undefeated, {one} one-loss, {eliminated} eliminated"
    )

    while undefeated > 0 or one > 1:
        if undefeated == 1 and one == 1:
            one = 2
            undefeated = 0
        else:
            eliminated += one // 2
            one = one - one // 2 + undefeated // 2
            undefeated -= undefeated // 2
        round += 1
        print(
            f"Round {round}: {undefeated} undefeated, {one} one-loss, {eliminated} eliminated"
        )
    print(f"There are {round} rounds.")

    print("")
