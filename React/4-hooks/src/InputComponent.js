import React, { useState } from "react";

export default function RegisterForm() {
  const [form, setForm] = useState({
    firstName: "Luke",
    lastName: "Jones",
    email: "lukeJones@sculpture.com",
  });
  const [count, setCount] = useState(0);

  return (
    <>
      <h3>useState</h3>
      <label className="form-label">
        First name:
        <input
          value={form.firstName}
          onChange={(e) => {
            setForm({
              ...form,
              firstName: e.target.value,
            });
          }}
        />
      </label>

      <label className="form-label">
        Last name:
        <input
          value={form.lastName}
          onChange={(e) => {
            setForm({
              ...form,
              lastName: e.target.value,
            });
          }}
        />
      </label>

      <label className="form-label">
        Email:
        <input
          type="email"
          value={form.email}
          onChange={(e) => {
            setForm({
              ...form,
              email: e.target.value,
            });
          }}
        />
      </label>

      <p>
        {form.firstName} {form.lastName} ({form.email})
      </p>

      <p>You clicked {count} times</p>
      <button onClick={() => setCount(count + 1)}>Click me</button>
    </>
  );
}
