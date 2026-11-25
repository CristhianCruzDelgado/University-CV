// ESLint flat configuration. Plain JavaScript, because ESLint loads it directly.
import eslintConfigPrettier from 'eslint-config-prettier';
import tseslint from 'typescript-eslint';

const MAX_PARAMETERS = 3;
const MAX_FUNCTION_LINES = 40;
const MAX_COMPLEXITY = 8;
const ALLOWED_NUMBERS = [-1, 0, 1, 2];

export default tseslint.config(
  // Subject code in assets/ keeps its own style and is never linted.
  { ignores: ['assets/', 'docs/', 'node_modules/', 'public/'] },
  {
    files: ['**/*.ts'],
    extends: [
      tseslint.configs.eslintRecommended,
      tseslint.configs.strictTypeChecked,
      tseslint.configs.stylisticTypeChecked,
    ],
    languageOptions: {
      parserOptions: {
        projectService: true,
        tsconfigRootDir: import.meta.dirname,
      },
    },
    rules: {
      eqeqeq: 'error',
      'no-var': 'error',
      'prefer-const': 'error',
      'no-console': ['error', { allow: ['warn', 'error'] }],
      'no-restricted-syntax': [
        'error',
        {
          selector: 'ExportDefaultDeclaration',
          message: 'Use named exports instead of default exports.',
        },
      ],
      complexity: ['error', MAX_COMPLEXITY],
      'max-params': ['error', MAX_PARAMETERS],
      'max-lines-per-function': [
        'error',
        { max: MAX_FUNCTION_LINES, skipBlankLines: true, skipComments: true },
      ],
      '@typescript-eslint/no-magic-numbers': [
        'error',
        {
          ignore: ALLOWED_NUMBERS,
          ignoreEnums: true,
          ignoreNumericLiteralTypes: true,
          ignoreReadonlyClassProperties: true,
        },
      ],
      '@typescript-eslint/consistent-type-definitions': ['error', 'interface'],
      '@typescript-eslint/explicit-function-return-type': [
        'error',
        { allowExpressions: true, allowTypedFunctionExpressions: true },
      ],
      '@typescript-eslint/array-type': ['error', { default: 'array-simple' }],
      '@typescript-eslint/no-explicit-any': 'error',
      '@typescript-eslint/switch-exhaustiveness-check': 'error',
      // Numbers in template literals are CSS values (scale, px, ms), which are safe.
      '@typescript-eslint/restrict-template-expressions': [
        'error',
        { allowNumber: true },
      ],
      '@typescript-eslint/naming-convention': [
        'error',
        {
          selector: 'variable',
          modifiers: ['const'],
          format: ['camelCase', 'UPPER_CASE'],
        },
        { selector: 'variable', format: ['camelCase'] },
        { selector: 'function', format: ['camelCase'] },
        { selector: 'typeLike', format: ['PascalCase'] },
      ],
    },
  },
  {
    // Vite requires a default export in its configuration file. This is the
    // only file where that export is allowed.
    files: ['vite.config.ts'],
    rules: { 'no-restricted-syntax': 'off' },
  },
  eslintConfigPrettier,
);
