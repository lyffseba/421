#!/bin/sh
# Functional smoke tests for buildable C projects. Exit non-zero on failure.
set -e
cd "$(dirname "$0")/.."
ROOT=$(pwd)
TMP=$(mktemp -d)
trap 'rm -rf "$TMP"; make -C push_swap fclean >/dev/null 2>&1 || true
      make -C fillit fclean >/dev/null 2>&1 || true
      make -C get_next_line fclean >/dev/null 2>&1 || true
      make -C lem_in fclean >/dev/null 2>&1 || true
      make -C corewar fclean >/dev/null 2>&1 || true
      make -C ft_printf fclean >/dev/null 2>&1 || true
      make -C libft fclean >/dev/null 2>&1 || true' EXIT

fail=0
ok() { printf 'ok  %s\n' "$1"; }
bad() { printf 'FAIL %s: %s\n' "$1" "$2"; fail=1; }

echo "== build =="
make -C libft >/dev/null
make -C ft_printf >/dev/null
make -C push_swap >/dev/null
make -C fillit >/dev/null
make -C get_next_line >/dev/null
make -C lem_in >/dev/null
make -C corewar >/dev/null

echo "== ft_printf =="
cat > "$TMP/pf.c" << 'C'
int ft_printf(const char *fmt, ...);
int main(void) {
	int n;
	n = ft_printf("%d %s %x %X %u %o %%\n", 42, "hi", 255, 255, 42u, 8);
	if (n < 10) return 1;
	ft_printf("%p\n", (void *)0xabc);
	ft_printf("%s\n", (char *)0);
	ft_printf("%lld\n", 123ll);
	return 0;
}
C
cc -I ft_printf/includes -I ft_printf/libft/includes "$TMP/pf.c" \
	ft_printf/libftprintf.a ft_printf/libft/libft.a -o "$TMP/pf"
out=$("$TMP/pf")
echo "$out" | head -1 | grep -q '42 hi ff FF 42 10 %' && ok ft_printf_basic || bad ft_printf_basic "$out"
echo "$out" | grep -q '0xabc' && ok ft_printf_ptr || bad ft_printf_ptr "$out"
echo "$out" | grep -q '(null)' && ok ft_printf_null || bad ft_printf_null "$out"
echo "$out" | grep -q '123' && ok ft_printf_lld || bad ft_printf_lld "$out"

echo "== push_swap =="
ps_out=$(./push_swap/push_swap 3 2 1 | ./push_swap/checker 3 2 1)
[ "$ps_out" = OK ] && ok push_swap_sort || bad push_swap_sort "$ps_out"
ps_out=$(./push_swap/push_swap 1 2 3 | ./push_swap/checker 1 2 3)
[ "$ps_out" = OK ] && ok push_swap_sorted || bad push_swap_sorted "$ps_out"
ps_out=$(printf 'sa\n' | ./push_swap/checker 2 1)
[ "$ps_out" = OK ] && ok push_swap_sa || bad push_swap_sa "$ps_out"
ps_out=$(printf 'bad\n' | ./push_swap/checker 1 2)
[ "$ps_out" = Error ] && ok push_swap_bad || bad push_swap_bad "$ps_out"

echo "== fillit =="
fill_out=$(./fillit/fillit fillit/resources/valid_files/test1)
echo "$fill_out" | grep -q 'A' && ok fillit_valid || bad fillit_valid "$fill_out"
fill_out=$(./fillit/fillit fillit/resources/invalid_files/test1 2>&1 || true)
echo "$fill_out" | grep -qi error && ok fillit_invalid || bad fillit_invalid "$fill_out"

echo "== gnl =="
printf 'one\ntwo\n' > "$TMP/g.txt"
gnl_out=$(./get_next_line/gnl "$TMP/g.txt")
echo "$gnl_out" | grep -q 'one' && echo "$gnl_out" | grep -q 'two' && ok gnl || bad gnl "$gnl_out"

echo "== lem_in =="
map=$(ls lem_in/resources/valid_maps | head -1)
li_out=$(./lem_in/lem-in < "lem_in/resources/valid_maps/$map")
echo "$li_out" | grep -q 'L' && ok lem_in || bad lem_in "no ant moves"

echo "== corewar =="
./corewar/asm corewar/Anastasia.s >/dev/null
cw_out=$(./corewar/corewar corewar/Anastasia.cor 2>&1)
echo "$cw_out" | grep -q 'Anastasia' && ok corewar_intro || bad corewar_intro "$cw_out"
echo "$cw_out" | grep -q 'has won' && ok corewar_win || bad corewar_win "$cw_out"
zork=corewar/resources/subject/vm_champs/champs/valid_champ/examples/zork.cor
cw_out=$(./corewar/corewar "$zork" corewar/Anastasia.cor 2>&1)
echo "$cw_out" | grep -q 'Player 2' && ok corewar_two || bad corewar_two "$cw_out"
rm -f corewar/Anastasia.cor

if [ "$fail" -ne 0 ]; then
	echo "test failed"
	exit 1
fi
echo "test ok"
