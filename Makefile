# Top-level Makefile

CLIENT = client
SERVER = server

SUBDIRS = config $(SERVER) $(CLIENT)

RED    = \033[1;31m
GREEN  = \033[1;32m
RESET  = \033[0;37m

all:
	@for dir in $(SUBDIRS); do \
		echo "$(GREEN)[Top] Building $$dir...$(RESET)"; \
		$(MAKE) --no-print-directory -C $$dir; \
	done
	@echo "$(GREEN)[Top] The building is done $(RESET)"

clean:
	@for dir in $(SUBDIRS); do \
		echo "$(RED)[Top] Cleaning $$dir...$(RESET)"; \
		$(MAKE) --no-print-directory -C $$dir clean; \
	done

fclean:
	@for dir in $(SUBDIRS); do \
		echo "$(RED)[Top] Full clean $$dir...$(RESET)"; \
		$(MAKE) --no-print-directory -C $$dir fclean; \
	done

re: fclean all

push:
	@read -p "Input the commit message: " msg; \
	git add .; \
	git commit -m "$$msg"; \
	git push

server_run:
	@$(SERVER)/server

client_run:
	@$(CLIENT)/client

.PHONY: all clean fclean re server_run client_run push

