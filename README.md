# 421

Offline vault of [École 42](https://42.fr/) projects for personal practice.

Complete source trees from the public repositories linked by
[anaiel/-42projects](https://github.com/anaiel/-42projects) are kept in full.
Nothing in those trees should be deleted.

## Contents

```
piscine_reloaded/   libft/              get_next_line/   fillit/
ft_printf/          push_swap/          lem_in/          corewar/
fdf/                fractol/            roger_skyline_1/ php_piscine/
workshops_machinelearning/
resources/          Norme PDF and upstream overview
```

| Path | Project | Notes |
|------|---------|-------|
| `piscine_reloaded/` | Piscine Reloaded | C basics |
| `libft/` | Libft | static library |
| `get_next_line/` | Get Next Line | fd / buffers |
| `fillit/` | Fillit | backtracking |
| `ft_printf/` | ft_printf | variadic printf |
| `push_swap/` | Push swap | stack sort |
| `lem_in/` | Lem-in | graphs |
| `corewar/` | Corewar | VM / asm |
| `fdf/` | FdF | wireframe |
| `fractol/` | Fract'ol | fractals |
| `roger_skyline_1/` | Roger-Skyline-1 | sysadmin |
| `php_piscine/` | Piscine PHP | web |
| `workshops_machinelearning/` | 42AI workshops | ML |
| `resources/norme.en.pdf` | The Norm | C standard at 42 |
| `resources/ORIGINAL_OVERVIEW.md` | Upstream README | grades / history |

## Build smoke

Requires `gcc` and `make`. Graphics/sysadmin trees need extra libs and are
not built here.

```
make check
```

Equivalent:

```
make -C libft && make -C libft fclean
make -C get_next_line && make -C get_next_line fclean
make -C fillit && make -C fillit fclean
make -C ft_printf && make -C ft_printf fclean
```

## Integrity

```
make verify
```

Confirms every expected project directory is present and non-empty.

## Provenance

| Directory | Upstream |
|-----------|----------|
| `resources/` | github.com/anaiel/-42projects |
| `piscine_reloaded/` | github.com/anaiel/PiscineReloaded |
| `libft/` | github.com/anaiel/libft |
| `get_next_line/` | github.com/anaiel/get_next_line |
| `fillit/` | github.com/anaiel/fillit |
| `ft_printf/` | github.com/anaiel/ft_printf |
| `push_swap/` | github.com/anaiel/push_swap |
| `lem_in/` | github.com/anaiel/lem-in |
| `corewar/` | github.com/anaiel/corewar |
| `fdf/` | github.com/anaiel/fdf |
| `fractol/` | github.com/anaiel/fractol |
| `roger_skyline_1/` | github.com/anaiel/roger-skyline-1 |
| `php_piscine/` | github.com/anaiel/php_piscine |
| `workshops_machinelearning/` | github.com/anaiel/workshops_machinelearning |

Educational mirror. Original authors retain rights to their code (see file
headers). Scaffolding in this repository root is MIT (LICENSE).

## Links

- https://github.com/lyffseba/421
- https://github.com/anaiel/-42projects
- https://42.fr/
