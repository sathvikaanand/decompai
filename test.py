from API_key import BASE_URL, API_KEY
from openai import OpenAI
client = OpenAI(api_key=API_KEY, base_url=BASE_URL)

# use client as usual
# see https://platform.openai.com/docs/guides/text-generation?lang=python


completion = client.chat.completions.create(
    model="gpt-4o-mini",
    messages=[
        {"role": "system", "content": "You are a helpful assistant."},
        {
            "role": "user",
            "content": "Write a haiku about recursion in programming."
        }
    ]
)

print(completion.choices[0].message)
