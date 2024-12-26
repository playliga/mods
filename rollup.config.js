import json from "@rollup/plugin-json";
import typescript from "@rollup/plugin-typescript";

/** @type {import('rollup').RollupOptions} */
export default {
  input: "cli/create.mts",
  output: {
    file: "build/liga-create.js",
    format: "cjs",
  },
  plugins: [json(), typescript()],
};
