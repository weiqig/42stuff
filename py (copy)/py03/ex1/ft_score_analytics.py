#!/usr/bin/env python3
import sys


def get_score_analytics(args: int) -> None:
    argc = len(args)
    print("=== Player Score Analytics ===")
    if argc == 0:
        a = "ft_score_analytics.py"
        print(f"No scores provided. Usage: python3 {a} <score1> <score2> ...")
        return
    else:
        score_list = []
        try:
            for score in range(len(args)):
                num = int(args[score])
                score_list.append(num)
        except Exception:
            print("Invalid score:", args[score])
        else:
            print("Scores processed:", args)
            print("Total players:", len(args))
            print("Total score:", sum(score_list))
            print("Average score:", sum(score_list)/(argc))
            print("High score:", max(score_list))
            print("Low score:", min(score_list))
            print(f"Scores range: {max(score_list) - min(score_list)}\n")


if __name__ == "__main__":
    get_score_analytics(sys.argv[1:])
