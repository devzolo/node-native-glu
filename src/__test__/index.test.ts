import { describe, it } from "node:test";
import assert from "node:assert";
import GLU from "../index.ts";

describe('GLU Build Tests', () => {
  it ('VERSION_1_1 == 1', () => {
    assert.strictEqual(GLU.VERSION_1_1, 1);
  })
});

