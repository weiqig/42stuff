def record_spell(spell_name: str, ingredients: str) -> str:
    from .validator import validate_ingredients
    output, is_valid = validate_ingredients(ingredients)
    if is_valid:
        return f"Spell recorded: {spell_name} ({output})"
    else:
        return f"Spell rejected: {spell_name} ({output})"
