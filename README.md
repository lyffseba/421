# 421

Offline vault of [École 42](https://42.fr/) projects for personal practice.

Complete source trees from the public repositories linked by
[anaiel/-42projects](https://github.com/anaiel/-42projects) are kept in full.
Nothing in those trees should be deleted.

## Contents

Curriculum order (top → bottom):

```
piscine_reloaded/
libft/
get_next_line/
fillit/
ft_printf/
push_swap/
lem_in/
corewar/
fdf/
fractol/
roger_skyline_1/
php_piscine/
workshops_machinelearning/
resources/
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

Requires `gcc`/`clang` and `make`. `make check` builds and fcleans the C
projects that do not need extra system libraries, and **fails if any target
fails**.

```
make check
```

Smoke targets: `libft`, `get_next_line`, `fillit`, `ft_printf`, `push_swap`,
`lem_in`, `corewar`.

Graphics (`fdf`, `fractol`) build against the bundled
`fdf/resources/minilibx_macos` (macOS / OpenGL + AppKit):

```
make -C fdf
make -C fractol
```

Not built by smoke: `roger_skyline_1` (docs only), `php_piscine` (needs PHP),
`lem_in/bonus_visualizer` (needs SDL2), ML notebooks.

## Integrity

```
make verify
```

Confirms every expected project directory is present and non-empty.

## Provenance

| Directory | Upstream |
|-----------|----------|
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
| `resources/` | github.com/anaiel/-42projects |

Educational mirror. Original authors retain rights to their code (see file
headers). Scaffolding in this repository root is MIT (LICENSE).

## Links

- https://github.com/lyffseba/421
- https://github.com/anaiel/-42projects
- https://42.fr/
