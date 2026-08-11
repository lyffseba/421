# 421 — repository maintenance (does not alter project trees)

PROJECTS = \
	piscine_reloaded libft get_next_line fillit \
	ft_printf push_swap lem_in corewar \
	fdf fractol roger_skyline_1 php_piscine \
	workshops_machinelearning

BUILD = libft get_next_line fillit ft_printf push_swap lem_in corewar

.PHONY: all verify check test clean help

all: verify

help:
	@echo "make verify  - every project tree present"
	@echo "make check   - verify + build/fclean smoke (fails on error)"
	@echo "make test    - functional smoke (build + run key binaries)"
	@echo "make clean   - fclean smoke targets if built"

verify:
	@fail=0; \
	for d in $(PROJECTS); do \
		if [ ! -d "$$d" ]; then echo "missing $$d"; fail=1; \
		elif [ -z "$$(find "$$d" -type f 2>/dev/null | head -1)" ]; then echo "empty $$d"; fail=1; \
		else n=$$(find "$$d" -type f | wc -l); printf "ok  %-28s %s files\n" "$$d" "$$n"; fi; \
	done; \
	test -f resources/norme.en.pdf || { echo "missing resources/norme.en.pdf"; fail=1; }; \
	test -f resources/ORIGINAL_OVERVIEW.md || { echo "missing resources/ORIGINAL_OVERVIEW.md"; fail=1; }; \
	if [ "$$fail" -ne 0 ]; then exit 1; fi; \
	echo "verify ok"

check: verify
	@fail=0; \
	for t in $(BUILD); do \
		echo "++ $$t"; \
		if $(MAKE) -C $$t; then \
			$(MAKE) -C $$t fclean >/dev/null || true; \
		else \
			echo "FAIL $$t"; fail=1; \
			$(MAKE) -C $$t fclean >/dev/null 2>&1 || true; \
		fi; \
	done; \
	if [ "$$fail" -ne 0 ]; then echo "check failed"; exit 1; fi; \
	echo "check ok"

test: verify
	@./scripts/test.sh

clean:
	@for t in $(BUILD); do $(MAKE) -C $$t fclean >/dev/null 2>&1 || true; done
