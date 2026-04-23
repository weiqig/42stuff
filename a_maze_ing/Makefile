.PHONY: run install build debug clean lint lint-strict

run:
	@python3 a_maze_ing.py config.txt

install:
	@echo "Installing packages and dependencies..."
	pip install -e .

build:
	@echo "Building mazegen package..."
	@python3 -m build

debug:
	@python3 -m pdb a_maze_ing.py

clean:
	@echo "Deleting '__pycache__'"
	@find . -type d -name '__pycache__' -not -path '*/.venv/*' -exec rm -r {} +
	@echo "Deleting '.egg-info' files"
	@find . -type d -name '*.egg-info' -not -path '*/.venv/*' -exec rm -r {} +
	@echo "Deleting '.mypy_cache' files"
	@find . -type d -name '.mypy_cache' -not -path '*/.venv/*' -exec rm -r {} +
	@echo "Deleting 'dist'"
	@rm -rf dist

lint:
	@echo "Linting with flake8..."
	@python3 -m flake8 . || true
	@echo "Running mypy..."
	@python3 -m mypy . --warn-return-any --warn-unused-ignores --ignore-missing-imports --disallow-untyped-defs --check-untyped-defs

lint-strict:
	@echo "Linting with flake8..."
	@python3 -m flake8 . || true
	@echo "Running mypy in strict mode..."
	@python3 -m mypy . --strict
