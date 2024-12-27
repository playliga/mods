import commonjs from "@rollup/plugin-commonjs";
import json from "@rollup/plugin-json";
import typescript from "@rollup/plugin-typescript";
import { nodeResolve } from "@rollup/plugin-node-resolve";

/** @type {import('rollup').RollupOptions} */
export default {
  external: ["node:sea"],
  input: "cli/create.mts",
  output: {
    file: "build/bundle.cjs",
    format: "cjs",
  },
  plugins: [json(), typescript(), nodeResolve(), commonjs()],
};
