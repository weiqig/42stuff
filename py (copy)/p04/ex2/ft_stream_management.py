#!/usr/bin/env python3
import sys


def stream_management() -> None:
    """
    Accepts stdin input, prints output as stdout / stderr
    """
    print("=== CYBER ARCHIVES - COMMUNICATION SYSTEM ===")
    try:
        userid = input("\nInput Stream active. Enter archivist ID: ")
        status = input("Input Stream active. Enter status report: ")
        print(f"\n[STANDARD] Archive status from {userid}: {status}")
        sys.stderr.write("[ALERT] System diagnostic: "
                         "Communication channels verified\n")
        sys.stdout.write("[STANDARD] Data transmission complete\n")
        print("\nThree-channel communication test successful.")
    except (KeyboardInterrupt, EOFError):
        return


stream_management()
