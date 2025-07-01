# Top-level Makefile

SUBDIRS = config server client

RED    = \033[1;31m
GREEN  = \033[1;32m
RESET  = \033[0;37m

all:
	@for dir in $(SUBDIRS); do \
		echo "$(GREEN)[Top] Building $$dir...$(RESET)"; \
		$(MAKE) -C $$dir; \
	done

clean:
	@for dir in $(SUBDIRS); do \
		echo "$(RED)[Top] Cleaning $$dir...$(RESET)"; \
		$(MAKE) -C $$dir clean; \
	done

fclean:
	@for dir in $(SUBDIRS); do \
		echo "$(RED)[Top] Full clean $$dir...$(RESET)"; \
		$(MAKE) -C $$dir fclean; \
	done

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re

