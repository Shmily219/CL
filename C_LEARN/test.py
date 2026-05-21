import anthropic

client = anthropic.Anthropic(
    base_url='https://api-inference.modelscope.cn',
    api_key='ms-1fbf172a-7f39-4fc1-a9be-146a25aba3b6',  # ModelScope Token
)

with client.messages.stream(
    model='deepseek-ai/DeepSeek-V4-Pro', # ModelScope Model-Id
    messages=[
        {
            "role": "user",
            "content": "你好"
        }
    ],
    max_tokens=1024
) as stream:
    for text in stream.text_stream:
        print(text, end="", flush=True)