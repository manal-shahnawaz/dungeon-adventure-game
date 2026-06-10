import os
from groq import Groq
from dotenv import load_dotenv

load_dotenv()

client = Groq(api_key=os.environ.get("GROQ_API_KEY"))

def main():
    base_dir = os.path.dirname(os.path.abspath(__file__))
    with open(os.path.join(base_dir, "prompt.txt"), "r") as f:
        action = f.read()

    chat = client.chat.completions.create(
        messages=[{
            "role": "system",
            "content": "You are a professional Dungeon Master. Give very short 1 sentence of easy but exciting story."
        }, {
            "role": "user",
            "content": action
        }],
        model="llama-3.1-8b-instant"
    )

    with open(os.path.join(base_dir, "response.txt"), "w") as f:
        f.write(chat.choices[0].message.content)

if __name__ == "__main__":
    main()