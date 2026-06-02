# Liasis_Library

Arduino library for the NorthernWidget Liasis longwave pyrgeometer.

## Standards

Follow the NW library standards for all work here. Two sources:
- **Within the NorthernWidget workspace:** the root `CLAUDE.md` (one level above `github/`) has the full checklist and code conventions.
- **Fresh clone / other location:** fetch [NorthernWidget/.github/RELEASING.md](https://github.com/NorthernWidget/.github/blob/main/RELEASING.md) for the release checklist and [NorthernWidget/.github/CONTRIBUTING.md](https://github.com/NorthernWidget/.github/blob/main/CONTRIBUTING.md) for naming and versioning conventions.

This is a **sensor library**. Schema 1 migration is required once the spec is stable and a Schema 0 snapshot tag exists. Liasis has no onboard MCU in current hardware; it will follow the Schema 1 sensor pattern when an MCU is added. Refer to the Liasis device appendix in [NW-Device-Specification](https://github.com/NorthernWidget/NW-Device-Specification).

## Hard rule

**Never** create a git tag, GitHub release, push to a shared remote, or submit to any external registry (Zenodo, Arduino Library Manager, etc.) unless explicitly asked in the current message. If in doubt, ask.
