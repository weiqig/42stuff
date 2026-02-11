from ex0.Card import Card

class SpellCard(Card):
    def __init__(self, name: str, cost: int, rarity: str, effect_type: str):
        super().__init__(name, cost, rarity)
        self.type = "Spell"
        self.effect_type = effect_type

    def play(self, game_state: dict) -> dict:
        if self.effect_type == "damage":
            effect = "Deal 3 damage to target"
        elif self.effect_type == "heal":
            effect = "Heal 5 health to target"
        elif self.effect_type == "buff":
            effect = "Buff target damage by 5"
        elif self.effect_type == "debuf":
            effect = "Debuff target damage by 2"
        result = {
            "card_played": self.name,
            "mana_used": self.cost,
            "effect": effect
        }
        return result
    
    def resolve_effect(self, targets: list) -> dict:
        for target in targets:
            if self.effect_type == "damage":
                print(f"damage dealt to {target.name}")
            elif self.effect_type == "heal":
                print(f"healed {target.name}")
            elif self.effect_type == "buff":
                print(f"buffed {target.name}")
            elif self.effect_type == "debuf":
                print(f"debuffed {target.name}")
