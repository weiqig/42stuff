#!/usr/bin/env python3
def check_validation(ingredients: str) -> None:
    from alchemy.grimoire.validator import validate_ingredients
    msg = f"validate_ingredients(\"{ingredients}\"):"
    result, __ = validate_ingredients(ingredients)
    print(f"{msg} {result}")


def perform_record(spell_name: str, ingredients: str) -> None:
    from alchemy.grimoire.spellbook import record_spell
    msg = f"record_spell(\"{spell_name}\", \"{ingredients}\"):"
    result = record_spell(spell_name, ingredients)
    print(f"{msg} {result}")


if __name__ == "__main__":
    print("=== Circular Curse Breaking ===")
    print("\nTesting ingredient validation:")
    check_validation("fire air")
    check_validation("dragon scales")
    print("\nTesting spell recording with validation:")
    perform_record("Fireball", "fire air")
    perform_record("Dark Magic", "shadow")
    print("\nTesting late import technique:")
    perform_record("Lightning", "air")
    print("\nCircular dependency curse avoided using late imports!")
    print("All spells processed safely!")
