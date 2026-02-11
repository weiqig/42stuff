#!/usr/bin/env python3
class SecurityError(Exception):
    def __init__(self, message: str) -> None:
        self.message = message

    def __str__(self) -> str:
        return (self.message)


def run_crisis_response(filename: str) -> None:
    status_msg = "Normal operations resumed"
    try:
        if filename == "classified_vault.txt":
            raise SecurityError("Security protocols deny access")
        with open(filename, "r") as file:
            content = file.read()
    except FileNotFoundError:
        print("RESPONSE: Archive not found in storage matrix")
        status_msg = "Crisis handled, system stable"
    except SecurityError as sec:
        print("RESPONSE:", sec)
        status_msg = "Crisis handled, security maintained"
    else:
        print(f"SUCCESS: Archive recovered - ``{content}''")
    finally:
        print("STATUS:", status_msg)


print("=== CYBER ARCHIVES - CRISIS RESPONSE SYSTEM ===")
print("\nCRISIS ALERT: Attempting access to 'lost_archive.txt'...")
run_crisis_response("lost_archive.txt")
print("\nCRISIS ALERT: Attempting access to 'classified_vault.txt'...")
run_crisis_response("classified_vault.txt")
print("\nROUTINE ACCESS: Attempting access to 'standard_archive.txt'...")
run_crisis_response("standard_archive.txt")
print("\nAll crisis scenarios handled successfully. Archives secure.")
